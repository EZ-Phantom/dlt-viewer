#ifndef CUSTOMMARKS_H
#define CUSTOMMARKS_H

#include <QWidget>

class MarksData;
class QLineEdit;

class CustomMarks : public QWidget
{
    Q_OBJECT
public:
    explicit CustomMarks(QWidget *parent = nullptr);

    QString getMarkText() const;

private:
    MarksData const *_data;
    QLineEdit *_lineEdit;

signals:
    void start(QString message);
    void stop(QString message);
};


class MarksData : public QObject
{
    Q_OBJECT
public:
    explicit MarksData(QObject *parent = nullptr);

    void load();
    void save(const QUrl &filePath);

private:

};

#endif // CUSTOMMARKS_H
