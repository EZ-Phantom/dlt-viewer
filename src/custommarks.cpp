#include "custommarks.h"

#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

CustomMarks::CustomMarks(QWidget *parent)
    : QWidget{parent}
    , _data(new MarksData(this))
    , _lineEdit(new QLineEdit)
{
    auto layout = new QVBoxLayout(this);

    auto inputLayout = new QHBoxLayout;
    inputLayout->addWidget(new QLabel("Text:"));
    inputLayout->addWidget(_lineEdit);
    layout->addLayout(inputLayout);

    auto start = new QPushButton("start");
    auto stop = new QPushButton("stop");
    connect(start, &QPushButton::clicked, [this](){emit this->start(_lineEdit->text());});
    connect(stop, &QPushButton::clicked, [this](){emit this->stop(_lineEdit->text());});

    auto buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(start);
    buttonsLayout->addWidget(stop);
    layout->addLayout(buttonsLayout);
}

QString CustomMarks::getMarkText() const
{
    return _lineEdit->text();
}

MarksData::MarksData(QObject *parent)
{

}
