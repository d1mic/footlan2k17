#ifndef VECTOR2_H_
#define VECTOR2_H_

template<typename T>
class Vector2
{
public:
    Vector2() {
        m_x = 0;
        m_y = 0;
    }
    Vector2(T x, T y) {
        m_x = x;
        m_y = y;
    }
    Vector2(const Vector2<T>& v) {
        m_x = v.x();
        m_y = v.y();
    }
    // geteri
    T x() const {
        return m_x;
    }
    T y() const {
        return m_y;
    }

    // seteri
    void setX(T x) {
        m_x = x;
    }
    void setY(T y) {
        m_y = y;
    }
    void setBoth(T x, T y) {
        m_x = x;
        m_y = y;
    }

    // operatori

    Vector2<T> operator+(const Vector2<T>& v) {
        return Vector2<T>(m_x+v.x(), m_y+v.y());
    }
    Vector2<T> operator-(const Vector2<T>& v) {
        return Vector2<T>(m_x-v.x(), m_y-v.y());
    }

    friend std::ostream& operator<< (std::ostream& out, const Vector2<T>& v)
    {
        out << "x: " << v.x() << " y: " << v.y();
        return out;
    }

private:
    T m_x;
    T m_y;
};

// predefinisani tipovi radi skracenog kucanja

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

#endif