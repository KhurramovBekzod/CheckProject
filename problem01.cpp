#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QColor>

// Base shape class
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

// Circle class
class circle final : public shape {
    int m_radius;

public:
    circle(int x, int y, int radius, QColor color) : shape(x, y, color), m_radius(radius) {}

    void draw(QPainter &painter) override {
        shape::draw(painter);
        painter.drawEllipse(m_x - m_radius, m_y - m_radius, m_radius * 2, m_radius * 2);
    }
};

// Rectangle class
class rectangle final : public shape {
    int m_width;
    int m_height;

public:
    rectangle(int x, int y, int width, int height, QColor color)
        : shape(x, y, color), m_width(width), m_height(height) {}

    void draw(QPainter &painter) override {
        shape::draw(painter);
        painter.drawRect(m_x, m_y, m_width, m_height);
    }
};

// Canvas class
class canvas final : public QWidget {
    shape *m_shape = nullptr;

public:
    void setShape(shape *newShape) {
        if (m_shape) delete m_shape;
        m_shape = newShape;
        update(); // triggers repaint
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

// Main function
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Shapes");
    window.resize(500, 500);

    auto layout = new QVBoxLayout(&window);
    auto drawArea = new canvas;
    drawArea->setFixedSize(500, 400);

    auto btnCircle = new QPushButton("Circle");
    auto btnRect = new QPushButton("Rectangle");

    layout->addWidget(drawArea);
    layout->addWidget(btnCircle);
    layout->addWidget(btnRect);

    // Correct tab order
    QWidget::setTabOrder(btnCircle, btnRect);

    QObject::connect(btnCircle, &QPushButton::clicked, [&]() {
        drawArea->setShape(new circle(250, 200, 50, Qt::red));
    });

    QObject::connect(btnRect, &QPushButton::clicked, [&]() {
        drawArea->setShape(new rectangle(150, 150, 200, 100, Qt::blue));
    });

    window.show();
    return QApplication::exec();
}
