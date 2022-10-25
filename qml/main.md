# Learning QML

 - [qmlscene](https://doc.qt.io/qt-5/qtquick-qmlscene.html): usado para executar apenas a interface gráfica, separada da lógica do C++
 - Object types usados no qml: https://doc.qt.io/qt-6/qtquick-qmlmodule.html
 - Qt Quick Controls QML Types: https://doc.qt.io/qt-6/qtquick-controls2-qmlmodule.html
---
## Connect Syntax
```c++
QLabel *label = new QLabel; // objeto a ser modificado
QScrollBar *scrollBar = new QScrollBar; // objeto que emite o sinal

QObject::connect(scrollBar, SIGNAL(valueChanged(int)), // quando esse mudar
label,  SLOT(setNum(int))); // esse é alterado
```

---

## 1 QML Basic Types
Alguns tipos básicos suportados pela linguagem nativa QML
 - **bool**: Binary true/false value
 - **double**: Number with a decimal point, stored in double precision
 - **enumeration**: Named enumeration value
 - **int**: Whole number, e.g. 0, 10, or -20
 - **list**: List of QML objects
 - **real**: Number with a decimal point
 - **string**: Free form text string
 - **urr**: Resource locator
 - **var**: Generic property type
---
## 2 Object Declarations
Um bloco de código entre chaves define a árvore de objetos a ser criada. Como também os atributos pertencentes a aquele objeto. Cada objeto pode também declararobjetos filhos usando declarações aninhadas de objetos.

**Exemplo**:
`Rectangle { width: 100; height: 100; color: "red" }`

**Exemplo de objeto com filhos:**
```qml
Rectangle {
    width: 100
    height: 100

    gradient: Gradient {
        GradientStop { position: 0.0; color: "yellow" }
        GradientStop { position: 1.0; color: "green" }
    }
}
```
Onde Rectangle é o root da árvore, que possui gradient como filho e gradiente possui dois filhos.

---

## 3 Attributes in Object Declarations
Uma declaração de objeto em um documento QML define um **novo tipo**. Isso também declara a hierarquia do objeto que será instanciado, caso uma instância desse tipo recém definido seja criado.

## 3.1 Conjunto de atributos objeto-tipo
Uma declaração de objeto em um documento QML define um novo tipo. Ele também declara uma hierarquia de objetos que será instanciada caso uma instância desse tipo recém-definido seja criada.
### 3.1.1 The id attribute:
Atributo único. Uma vez instanciado, não pode ser alterado por nenhum tipo. Usado para ser referenciado por outros objetos.

### 3.1.2 Property attributes: 
Pode ser um atributo estático de um objeto ou vinculado a uma expressão dinâmica. Esse valor pode ser lido e modificado por outro objetona maioria dos casos. 
#### 3.1.2.1 Definindo uma Property Attributes:
Uma propriedade pode ser definida por um tipo em C++ registrando a Q_PROPERTY de uma classe que é então registrada com o sistema de tipos QML.
#### 3.1.2.2 Para criar uma propriedade customizada de um tipo de objeto:
  [default] [required] [readonly] property <propertyType> <propertyName>
  Isso implicitamente cria um value-change signal para essa propriedade. Como também um signal handler, chamado: on<PropertyName>Change. Onde <PropertyName> é o nome da propriedade, com a primeira letra maiuscula.
#### 3.1.2.3 Tipos válidos em uma definição de propriedade customizada:
Qualquer tipo básico do QML, pode ser usado como uma propriedade customizada. **Exemplo:** 

```qml
Item {
    property int someNumber
    property string someString
    property url someUrl
}
```

Note que o tipo var é genérico e pode armazenar qualquer tipo de valor:
 - property var someNumber: 1.5
 - property var someString: "abc"
 - property var someBool: true
 - property var someList: [1, 2, "three", "four"]
 - property var someObject: Rectangle { width: 100; height: 100; color: "red" }

Também pode usar qualquer tipo de objeto como propriedade: 
 - property Item someItem
 - property Rectangle someRectangle

#### 3.1.2.4 Assigning Values to Property Attributes
O valor de uma propriedade de um objeto pode ser instanciado de 2 formas:
 - Uma atribuição de valor na inicialização: <propertyName> : <value>
**Exemplo:** 
```
Rectangle {
    color: "red"
    property color nextColor: "blue" // combined property declaration and initialization
}
```
 - Uma atribuição de valor imperativo: [<objectId>.]<propertyName> = value
**Exemplo:** 
```
Rectangle {
    id: rect
    Component.onCompleted: {
        rect.color = "red"
    }
}
```

#### 3.1.2.5 Static Values and Binding Expression Values
**Valor Estático:** Um valor constante que não depende de outras propriedades 
** Binding Expression:**  Uma expressão Javascript que descreve um relacionamento de propriedades com. A variável nessa expressão é chamada de dependência de propriedade.
O mecanismo QML impõe o relacionamento entre uma propriedade e suas dependências. Quando qualquer uma das dependências muda de valor, o mecanismo QML reavalia automaticamente a expressãode ligação e atribui o novo resultado à propriedade.
** Exemplo dos dois tipos:** 

```
Rectangle {
    // both of these are static value assignments on initialization
    width: 400
    height: 200

    Rectangle {
        // both of these are binding expression value assignments on initialization
        width: parent.width / 2
        height: parent.height
    }
}
```
#### 3.1.2.6 Tipos especiais 
Atributos de propriedades Lista de Objetos
Uma propriedade de tipo de lista pode ser atribuída a uma lista de valores de tipo de objeto QML. A sintaxe para definir um valor de lista de objetos é uma lista separada por vírgulas entre colchetes:
**Exemplo:**
```
Rectangle {
    // declaration without initialization
    property list<Rectangle> siblingRects

    // declaration with initialization
    property list<Rectangle> childRects: [
        Rectangle { color: "red" },
        Rectangle { color: "blue"}
    ]
}
```

## 4 Grouped Properties
Em alguns casos, as propriedades contêm um grupo lógico de atributos de subpropriedade. Esses atributos de subpropriedade podem ser atribuídos usando a notação de ponto ou notação de grupo. 
**Exemplo:** 
```
Text {
    //dot notation
    font.pixelSize: 12
    font.b: true
}

Text {
    //group notation
    font { pixelSize: 12; b: true }
}
```
## 5 Property Alias
São referências para outras propriedades. Ao invés de um propriedade comum, essa não aloca um novo espaço em memória, pois, está conectada com a propriedade recém declarada chamada de Property Alias. Uma referência direta para uma propriedade já existente. Usando a keyword: alias.
Exemplo: 
Rectangle {
    property alias buttonText: textItem.text

    width: 100; height: 30; color: "yellow"

    Text { id: textItem }
}

### 6 Default Properties
Uma definição de objeto pode ter apenas uma default property. Sendo essa atribuida se outro objeto declarado aninhado sem uma inicialização para a propriedade determinada. Usa-se a keyword `default`

<faltando alguns tipos de propriedades>

## 7 Signal attributes
Signal é uma notificação de algum objeto que ocorreu algum evento, como por exemplo, uma propriedade mudou, uma animação começou ou parou ou quando uma imagem foi baixada

Um objeto pode ser notificado através de um `signal handler` sempre que um determinado `signal` for emitido. A `Signal Handler` é declarado com a syntax on<Signal>, onde <Signal> é o nome do `Signal` com a primeira letra maiuscula. O `Signal Handler` deve ser definido dentro da definição do objeto que emite o `signal`.
Exemplo de `Signal Handler`: 
onClicked abaixo é declarado dentro da definição do objeto MouseArea e é invocado quando o MouseArea é clicado, fazendo com que uma mensagem do console seja impressa:
```
Item {
    width: 100; height: 100

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("Click!")
        }
    }
} 
```
#### 7.1 Definindo `Signal Attributes`
Pode ser definido por um tipo em C++ registrando o Q_signal de um classe que é então registrada com o sistema de tipos QML.
Também pode ser definido usando QML: 

```
import QtQuick 2.0

Item {
    signal clicked
    signal hovered()
    signal actionPerformed(string action, var actionResult)
}
```
Se o `signal` não tem parâmetros, os "()" são opcionais.

## 8 Signal handler attributes
## 9 Method attributes
## 10 Attached properties and attached signal handler attributes
## 11 Enumeration attributes
## 12 References
 - https://doc.qt.io/qt-5/qmlfirststeps.html
 - https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
 - https://doc.qt.io/qt-5/qtqml-syntax-objectattributes.html
 - https://doc.qt.io/qt-5/properties.html
 - https://doc.qt.io/qt-5/qtquick-modelviewsdata-modelview.html
 - https://doc.qt.io/qt-5/qtqml-syntax-signals.html
 - https://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterType 
--- 
