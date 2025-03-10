#include <cmath>
#include <iostream>
#include <vector>
// #include "matrix3x3.h"


using namespace std;

class vector2 {
private:
        vector<float> v;

public:
        vector2() : v{0.0f, 0.0f} {}

        vector2(float x, float y) : v{x, y} {}

        [[nodiscard]] float get_x() const {
                return v[0];
        }
        [[nodiscard]] float get_y() const {
                return v[1];
        }

        float dot (vector2 &other) const {
                return v[0] * other.get_x() + v[1] * get_y();
        }

        float get_length() const {
                return sqrt(v[0] * v[0] + v[1] * v[1]);
        }

        vector2 normalize() const {
                float length = get_length();
                if (length == 0.0f) {
                        throw std::out_of_range("The length is 0");
                }else {
                        return vector2(get_x() / length * 1.0, get_y() / length * 1.0);
                }
        }

        friend std::ostream& operator<<(std::ostream &os, const vector2& vec) {
                os << "(" << vec.get_x() << ", " << vec.get_y() << ")";
                return os;
        }

        vector2 operator+(const vector2& vec) const {
                return vector2 (v[0] + vec.get_x(), v[1] + vec.get_y());
        }
        vector2 operator-(const vector2& vec) const {
                return vector2 (v[0] - vec.get_x(), v[1] - vec.get_y());;
        }
        vector2 operator*(const float scalar) const {
                return vector2 (v[0] * scalar * 1.0, v[1] + scalar * 1.0);
        }




};






int main() {
        using std::cout;

        vector2 a{ 10.0f, 20.0f};
        vector2 b{-42.0f, 4.0f};
        vector2 c; // create a zero vector


        cout << "a.x: " << a.get_x() << ", a.y: " << a.get_y() << "\n";
        cout << "b.x: " << b.get_x() << ", b.y: " << b.get_y() << "\n";

        cout << a << " + "   << b   << " = " << (a + b)   << "\n";
        cout << a << " - "   << b   << " = " << (a - b)   << "\n";
        cout << a << " * "   << 2.0 << " = " << (a * 2.0) << "\n";
        cout << a << " dot " << b   << " = " << a.dot(b)  << "\n";

        cout << "||"  << a << "|| = " << a.get_length()             << "\n";
        cout << "||"  << c << "|| = " << c.get_length()             << "\n";
        cout << "||^" << b << "|| = " << b.normalize().get_length() << "\n";
        return 0;
}

