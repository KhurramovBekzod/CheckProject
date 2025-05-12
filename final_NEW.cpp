#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QPalette>


class shape {
protected:
    int m_x;
    int m_y;
    QColor m_color;

public:
    shape(int x, int y, QColor color) : m_x(x), m_y(y), m_color(color) {}
    virtual ~shape() = default;

    virtual void draw(QPainter &painter) {
        painter.setBrush(m_color);
        painter.setPen(Qt::NoPen);
    }
};

class rectangle final : public shape {
    int m_size;

public:
    rectangle(int x, int y, int size, QColor color)
        : shape(x, y, color), m_size(size) {}

    void draw(QPainter &painter) override {
        shape::draw(painter);
        int half = m_size / 2;
        painter.drawRect(m_x - half, m_y - half, m_size, m_size);
    }
};

class triangle final : public shape {
    int m_size;

public:
    triangle(int x, int y, int size, QColor color)
        : shape(x, y, color), m_size(size) {}

    void draw(QPainter &painter) override {
        shape::draw(painter);
        QPolygon poly;
        poly << QPoint(m_x, m_y - m_size / 2)               // top
             << QPoint(m_x - m_size / 2, m_y + m_size / 2)  // bottom left
             << QPoint(m_x + m_size / 2, m_y + m_size / 2); // bottom right
        painter.drawPolygon(poly);
    }
};

class canvas final : public QWidget {
    shape *m_shape = nullptr;

public:
    canvas(QWidget *parent = nullptr) : QWidget(parent) {
        setAutoFillBackground(true);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::black);
        setPalette(pal);
    }

    void setShape(shape *newShape) {
        delete m_shape;
        m_shape = newShape;
        update();
    }

    ~canvas() {
        delete m_shape;
    }

protected:
    void paintEvent(QPaintEvent *) override {
        if (m_shape) {
            QPainter painter(this);
            m_shape->draw(painter);
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Shapes");
    window.resize(500, 500);

    auto layout = new QVBoxLayout(&window);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    auto drawArea = new canvas;
    drawArea->setFixedSize(500, 420);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(10);
    buttonLayout->setContentsMargins(10, 10, 10, 10);

    auto btnRect = new QPushButton("Rectangle");
    auto btnTri = new QPushButton("Triangle");

    btnRect->setFixedHeight(40);
    btnTri->setFixedHeight(40);

    buttonLayout->addWidget(btnRect);
    buttonLayout->addWidget(btnTri);

    layout->addWidget(drawArea);
    layout->addLayout(buttonLayout);

    QWidget::setTabOrder(btnRect, btnTri);

    QObject::connect(btnRect, &QPushButton::clicked, [&]() {
        drawArea->setShape(new rectangle(250, 210, 300, Qt::blue));
    });

    QObject::connect(btnTri, &QPushButton::clicked, [&]() {
        drawArea->setShape(new triangle(250, 210, 300, Qt::red));
    });

    window.show();
    return QApplication::exec();
}
