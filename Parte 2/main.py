import sys
from PyQt5.QtWidgets import QApplication, QDialog, QMainWindow
from ui_mainwindow import Ui_MainWindow
from ui_helpdialog import Ui_Dialog

app = QApplication(sys.argv)

# Setting up main window
mainWindow = QMainWindow()
mainUi = Ui_MainWindow()
mainUi.setupUi(mainWindow)

# Setting up help window
helpDialog = QDialog()
helpUi = Ui_Dialog()
helpUi.setupUi(helpDialog)

mainWindow.show()
helpDialog.show()
sys.exit(app.exec_())
