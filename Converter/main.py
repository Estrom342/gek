import sys

from PyQt5.QtWidgets import QApplication

from converterWidget import ConverterWidget

app = QApplication(sys.argv)
w = ConverterWidget()
w.show()
w.resize(780, 480)
sys.exit(app.exec())
