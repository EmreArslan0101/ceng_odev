/**
    @author Emre ARSLAN
*/

#include "md4c-html.h"
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QLabel>
#include <QString>
#include <QByteArray>
#include <QTextCodec>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUi(this); 

        connect(writeableZone, &QPlainTextEdit::textChanged, this, &MainWindow::updateMarkdown);
    }

private:
    void updateMarkdown() {
        QString markdownText = writeableZone->toPlainText();
        QByteArray htmlResult;

        // md4c HTML renderer callback
        auto process_output = [](const char* text, void* userdata) {
            QByteArray* output = static_cast<QByteArray*>(userdata);
            output->append(text);
        };

        // Parse Markdown and convert to HTML
        int result = md_html(markdownText.toUtf8().constData(),
                             markdownText.toUtf8().size(),
                             process_output,
                             &htmlResult,
                             MD_FLAG_NOHTML);  

        if (result == 0) {
            markdownZone->setTextFormat(Qt::RichText);
            markdownZone->setText(QString::fromUtf8(htmlResult));
        } else {
            markdownZone->setText("Markdown işlenemedi!");
        }
    }
};
