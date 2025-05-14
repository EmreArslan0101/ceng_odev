# This Python file uses the following encoding: utf-8
import sys
from PySide6.QtWidgets import QApplication, QMainWindow

class MainApp(QMainWindow):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("TXT to MD Note App")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainApp()
    window.show()
    sys.exit(app.exec())
