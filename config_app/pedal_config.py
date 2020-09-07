import sys
import serial
from cobs import cobs
from PyQt5.QtWidgets import QApplication, QLabel, QMainWindow, QWidget, QPushButton, QVBoxLayout
from PyQt5.QtCore import Qt

class MainWindow(QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)

        self.setWindowTitle("Midi Pedal Config")

        self.config_window = QWidget()

        self.button = QPushButton('Kick Me')
        self.button.clicked.connect(self.onButtonClicked) 
        layout = QVBoxLayout()
        layout.addWidget(self.button)
        self.config_window.setLayout(layout)

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

    def onButtonClicked(self):
        msg = self.encodeMessage()
        encoded = cobs.encode(msg)
        encoded = bytearray(encoded)
        encoded.append(0)
        print("Sending: {}".format(encoded))
        
        ser = serial.Serial()
        ser.baudrate = 9600
        ser.port = '/dev/cu.usbmodem57189301'
        ser.bytesize = serial.EIGHTBITS #number of bits per bytes
        ser.parity = serial.PARITY_NONE #set parity check: no parity
        ser.stopbits = serial.STOPBITS_ONE #number of stop bit
        ser.timeout = 3
        ser.open()
        ser.write(encoded)




app = QApplication(sys.argv)

window = MainWindow()
window.show()

app.exec_()
