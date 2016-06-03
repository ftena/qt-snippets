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

    if (!shared_memory.attach()) {
        qDebug() << "Unable to attach to shared memory segment. Error: " << shared_memory.error();
        return -1;
    }

    int size = sizeof(MyStruct);
    MyStruct m2;

    // Read from shared memory
    shared_memory.lock();

    // Copy from shared memory to m2
    memcpy(&m2, (char*)shared_memory.constData(), std::min(shared_memory.size(), size));

    // Or... copy from shared memory to QByteArray
    QByteArray byte_array_m2((char*)shared_memory.constData(), size);

    shared_memory.unlock();

    // Print m2 retrieved using memcpy
    std::cout << m2;

    // Or by using QByteArray
    const MyStruct* m2_2 = static_cast< const MyStruct* >((const void*)byte_array_m2.constData());
    std::cout << *m2_2;

    std::this_thread::sleep_for(std::chrono::milliseconds(50000));

    return 0;
}
