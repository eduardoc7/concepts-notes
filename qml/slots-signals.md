# Learning Slots and Signals
 - Implementado no QT Framework
 - Uma forma dos objetos instanciados se comunicarem
 - Para emitir um signal é usado a keyword `emit`
 - Podemos conectar um signal com múltiplos slots

## Syntax
1. Um objeto que emite o sinal
2. Qual o sinal?
3. O objeto que implementa o slot
4. Qual o slot?

Conectamos os slots e signals usando um método estático do QObject
```qml
QObjet::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);

// 1. slider é o objeto que emite o sinal
// 2. &QSlider::valueChanged é o signal
// 3. spinBox é o objeto que implementa o slot
// 4. &QSpinBox::setValue é o slot (apenas um método regular do c++)
```

## Variations of Signal/Slot Connections

<p align="center">
    <img alt="Connections Variations" src="https://i.imgur.com/juK4TVI.png" />   
</p>

## Connect Approaches

 - Function Pointers
    - `connect(const QObject * sender, PointerToMemberFunction signal, const QObject * receiver, PointerToMemberFunction method)`
    - Mais usado nas versões atuais

 - SIGNAL/SLOT Macros
    - `connect(const QObject * sender, const char * signal, const QObject * receiver, const char * method)`
    - ```qml
        QSlider *slider = new QSlider(QT::Horizontal);
        QSpinBox *spin = new QSpinBox;
        QObject::connect(slider, SIGNAL(valueChanged(int), spin, SLOT(setValue(int))))
        ```
    - Menos preferível, pois, não gera erros de compilação quando o connect não funciona
 - Function Objects
    - Lambda Functions
    - Functors
    - Standalone functions

## Implicit Conversion
Usado para overloading de métodos, disponível apenas na versão 5.7
```qml
QObject::connect(
    slider,
    &QSlider::valueChanged,
    integerLcd,
    QOverload<int>::of(&QLCDNumber:display)
);
```