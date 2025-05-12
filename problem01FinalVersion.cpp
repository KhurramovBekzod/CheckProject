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
    }
};

class circle final : public shape {
    int m_radius;

public:
    circle(int x, int y, int radius, QColor color)
        : shape(x, y, color), m_radius(radius) {}

    void draw(QPainter &painter) override {
        shape::draw(painter);
        painter.drawEllipse(m_x - m_radius, m_y - m_radius, m_radius * 2, m_radius * 2);
    }
};

class rectangle final : public shape {
    int m_width;
    int m_height;

public:
    rectangle(int x, int y, int width, int height, QColor color)
        : shape(x, y, color), m_width(width), m_height(height) {}

    void draw(QPainter &painter) override {
        shape::draw(painter);
        painter.drawRect(m_x - m_width / 2, m_y - m_height / 2, m_width, m_height);
    }
};

class canvas final : public QWidget {
    shape *m_shape = nullptr;

public:
    canvas(QWidget *parent = nullptr) : QWidget(parent) {
        setAutoFillBackground(true);
        QPalette pal = palette();
        pal.setColor(QPalette::Window, Qt::white);
        setPalette(pal);
    }

    void setShape(shape *newShape) {
        delete m_shape;
        m_shape = newShape;
        update(); // trigger repaint
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
    drawArea->setFixedSize(500, 420); // height slightly less for buttons

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(10);
    buttonLayout->setContentsMargins(10, 10, 10, 10);

    auto btnCircle = new QPushButton("Circle");
    auto btnRect = new QPushButton("Rectangle");

    buttonLayout->addWidget(btnCircle);
    buttonLayout->addWidget(btnRect);

    layout->addWidget(drawArea);
    layout->addLayout(buttonLayout);

    QWidget::setTabOrder(btnCircle, btnRect);

    QObject::connect(btnCircle, &QPushButton::clicked, [&]() {
        drawArea->setShape(new circle(250, 210, 150, Qt::red)); // center + radius
    });

    QObject::connect(btnRect, &QPushButton::clicked, [&]() {
        drawArea->setShape(new rectangle(250, 210, 300, 300, Qt::blue)); // large square
    });

    window.show();
    return QApplication::exec();
}
