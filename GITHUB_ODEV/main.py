# This Python file uses the following encoding: utf-8
import sys
from PySide6.QtWidgets import QApplication, QMainWindow
from mainui import Ui_MainWindow
import markdown

class MainApp(QMainWindow):
    
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        
        # Gösterilen Markdown verisini yazdıkça güncellemek adına, 
        # writeablezone nesnesini textChanged sinyaline bağlıyorum 
        self.ui.writeableZone.textChanged.connect(self.update_markdown_preview)

        # Markdown içeriğini herhangi bir hata yaşanamamsı adına önceden siliyorum
        self.update_markdown_preview()
    
    # Yazılan MD yazısını MD formatına uygun bir HTML'ye çeviriyor 
    def md_converter(self, text_content: str) -> str:
        md_html = markdown.markdown(text_content, extensions=['extra', 'codehilite'])
        return md_html
    
    # Çevrilen HTML verisini kullanarak bir görsel sonuç ortaya çıkartıyor
    # ya da Markdown HTML'nin yazılacağı yeri temizliyor
    def update_markdown_preview(self):

        markdown_text = self.ui.writeableZone.toPlainText()
        
        html_output = self.md_converter(markdown_text)
        
        # HTML Markdown verisini uygun biçimde markdownzone nesnesine atıyorum
        self.ui.markdownZone.setHtml(html_output)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainApp()
    window.show()
    sys.exit(app.exec())
