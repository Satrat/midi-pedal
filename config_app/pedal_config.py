import sys
import serial
from cobs import cobs
from PyQt5.QtWidgets import QApplication, QLabel, QMainWindow, QWidget, QPushButton, QVBoxLayout, QHBoxLayout, QComboBox, QGridLayout, QCheckBox
from PyQt5.QtCore import Qt

class MidiMessageConfigOptions(QWidget):
    def __init__(self):
        super(MidiMessageConfigOptions,self).__init__() 

        self.midi_msg_type_label = QLabel("Message Type: ")
        self.midi_msg_type = QComboBox()
        self.midi_msg_type.addItem("NOTE_ON")
        self.midi_msg_type.addItem("NOTE_OFF")
        self.midi_msg_type.addItem("CONTROL_CHANGE")
        self.midi_msg_type.addItem("PROGRAM_CHANGE")

        self.midi_channel_label = QLabel("Channel: ")
        self.midi_channel = QComboBox()
        for i in range(16):
            self.midi_channel.addItem(str(i))

        self.midi_data1_label = QLabel("Data Byte 1: ")
        self.midi_data1 = QComboBox()
        self.midi_data2_label = QLabel("Data Byte 2: ")
        self.midi_data2 = QComboBox()
        for i in range(128):
            self.midi_data1.addItem(str(i))
            self.midi_data2.addItem(str(i))

        self.layout = QGridLayout()
        self.layout.addWidget(self.midi_msg_type_label,0,0)
        self.layout.addWidget(self.midi_msg_type,0,1)
        self.layout.addWidget(self.midi_channel_label,1,0)
        self.layout.addWidget(self.midi_channel,1,1)
        self.layout.addWidget(self.midi_data1_label,2,0)
        self.layout.addWidget(self.midi_data1,2,1)
        self.layout.addWidget(self.midi_data2_label,3,0)
        self.layout.addWidget(self.midi_data2,3,1)
        self.setLayout(self.layout)

    def disableAll(self):
        self.midi_msg_type.setEnabled(False)
        self.midi_channel.setEnabled(False)
        self.midi_data1.setEnabled(False)
        self.midi_data2.setEnabled(False)

    def enableAll(self):
        self.midi_msg_type.setEnabled(True)
        self.midi_channel.setEnabled(True)
        self.midi_data1.setEnabled(True)
        self.midi_data2.setEnabled(True)

class StompConfigOptions(QWidget):
    def __init__(self, stomp_id):
        super(StompConfigOptions,self).__init__() 
        self.stomp_id = stomp_id

        self.title = QLabel()
        self.title.setText(f"Stomp Box {stomp_id}")
        self.title.setAlignment(Qt.AlignCenter)
        self.title.setStyleSheet("font-weight: bold; padding-bottom: 10px;")

        self.trigger_release = QCheckBox("Message on Release")
        self.trigger_release.toggled.connect(self.on_release_trigger_toggled)

        self.cycle_press = QCheckBox("Cycle on Press")
        self.cycle_press.toggled.connect(self.on_cycle_press_toggled)
        self.cycle_length_label = QLabel("Cycle Length: ")
        self.cycle_length = QComboBox()
        for i in range(1,8):
            self.cycle_length.addItem(str(i))
        self.cycle_length.setEnabled(False)

        self.press_label = QLabel("Press Message")
        self.press_label.setAlignment(Qt.AlignCenter)
        self.press_midi_options = MidiMessageConfigOptions()

        self.release_label = QLabel("Release Message")
        self.release_label.setAlignment(Qt.AlignCenter)
        self.release_midi_options = MidiMessageConfigOptions()
        self.release_midi_options.disableAll()
        
        self.layout = QGridLayout()
        self.layout.addWidget(self.title,0,0,1,4)
        self.layout.addWidget(self.trigger_release,1,0,1,4)
        self.layout.addWidget(self.cycle_press,2,0)
        self.layout.addWidget(self.cycle_length_label,2,2)
        self.layout.addWidget(self.cycle_length,2,3)
        self.layout.addWidget(self.press_label,3,0,1,4)
        self.layout.addWidget(self.press_midi_options,4,0,4,4)
        self.layout.addWidget(self.release_label,8,0,1,4)
        self.layout.addWidget(self.release_midi_options,9,0,4,4)
        
        self.setLayout(self.layout)

    def on_release_trigger_toggled(self):
        if self.trigger_release.isChecked():
            self.release_midi_options.enableAll()
            self.cycle_press.setChecked(False)
            self.cycle_press.setEnabled(False)
        else:
            self.release_midi_options.disableAll()
            self.cycle_press.setEnabled(True)

    def on_cycle_press_toggled(self):
        if self.cycle_press.isChecked():
            self.cycle_length.setEnabled(True)
        else:
            self.cycle_length.setEnabled(False)

class PedalConfigOptions(QWidget):
    def __init__(self, num_stomps):
        super(PedalConfigOptions,self).__init__() 

        self.num_stomps = num_stomps
        self.stomps = []
        for i in range(self.num_stomps):
            self.stomps.append(StompConfigOptions(i+1))

        self.layout = QHBoxLayout()
        for stomp in self.stomps:
            self.layout.addWidget(stomp)

        self.setLayout(self.layout)

class MainWindow(QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)

        self.setWindowTitle("Midi Pedal Config")
        self.setMaximumWidth(1000)

        self.config_window = QWidget()

        self.num_stomps = 4
        self.pedal_config = PedalConfigOptions(self.num_stomps)

        self.button = QPushButton('Configure Pedal Board')
        self.button.setMaximumWidth(400)
        self.button.clicked.connect(self.onButtonClicked) 

        layout = QVBoxLayout()
        layout.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.pedal_config)
        layout.addWidget(self.button, alignment=Qt.AlignCenter)
        self.config_window.setLayout(layout)

        self.serial = None

        self.setCentralWidget(self.config_window)

    def encodeMessage(self):
        #psssdrrr MC D1 D2
        p = 1
        s = 3
        d = 0
        r = 5
        M = 12
        C = 2
        P = 50
        V = 0

        b1 = (p << 7) | (s << 4) | (d << 3) | r
        b2 = (M << 4) | C
        b3 = P
        b4 = V
        msg = [b1,b2,b3,b4]

        print(msg)
        print([hex(m) for m in msg])
        print([bin(m) for m in msg])
        byte_msg = bytearray()
        byte_msg.append(b1)
        byte_msg.append(b2)
        byte_msg.append(b3)
        byte_msg.append(b4)
        return bytearray(byte_msg)

    def sendCobsMessage(self, msg):
        cobs_msg = cobs.encode(msg)
        cobs_msg = bytearray(cobs_msg)
        cobs_msg.append(0)
        print(f"Sending: {cobs_msg}")
        self.serial.write(cobs_msg)

    def serialOpen(self, baudrate=9600, port='/dev/cu.usbmodem57189301', timeout=3):
        if self.serial is not None:
            self.serial.close()
        else:
            self.serial = serial.Serial()

        self.serial.baudrate = baudrate
        self.serial.port = port
        self.serial.bytesize = serial.EIGHTBITS #number of bits per bytes
        self.serial.parity = serial.PARITY_NONE #set parity check: no parity
        self.serial.stopbits = serial.STOPBITS_ONE #number of stop bit
        self.serial.timeout = timeout
        self.serial.open()

    def serialClose(self):
        self.serial.close()

    def onButtonClicked(self):
        self.serialOpen()
        msg = self.encodeMessage()
        self.sendCobsMessage(msg)
        self.serialClose()

if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    app.exec_()
