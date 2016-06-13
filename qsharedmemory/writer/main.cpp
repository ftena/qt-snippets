#include <iostream>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <thread>

#include <QSharedMemory>
#include <QByteArray>
#include <QDebug>

struct MyStruct {
    unsigned char a;
    int b;
    char d[100];
};

std::ostream& operator<< (std::ostream& stream, const MyStruct& m) {
   std::cout << m.a << '\n';
   std::cout << m.b << '\n';
   std::cout << m.d << '\n';
   return stream;
}


int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QSharedMemory shared_memory("test");

    char buffer[sizeof(MyStruct)]; // let compiler decide size of frame
    int size = sizeof(MyStruct);
    MyStruct m1;

    // Init struct
    m1.a = 'c';
    m1.b = 100;
    strcpy(m1.d, "testing");

    // Copy m1 to buffer
    std::memcpy(buffer, &m1, size);

    // Print m1
    std::cout << m1;

    // Create QByteArray using the buffer
    QByteArray byte_array_m1(buffer, size);

    if (!shared_memory.create(size)) {
        qDebug() << "Unable to create shared memory segment. Error: "  << shared_memory.error();
        return -1;
    }

    // Write in shared memory
    shared_memory.lock();

    char *to = (char*)shared_memory.data();
    const char *from = byte_array_m1.data();
    std::memcpy(to, from, std::min(shared_memory.size(), size));

    shared_memory.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    return 0;
}
