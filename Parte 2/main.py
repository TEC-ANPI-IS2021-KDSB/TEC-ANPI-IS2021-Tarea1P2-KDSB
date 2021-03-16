import sys
from PyQt5.QtWidgets import QApplication, QDialog, QMainWindow
from ui_mainwindow import Ui_MainWindow
from ui_helpdialog import Ui_Dialog

app = QApplication(sys.argv)

# Setting up main window
mainWindow = QMainWindow()
mainUi = Ui_MainWindow()
mainUi.setupUi(mainWindow)
mainWindow.show()
sys.exit(app.exec_())
