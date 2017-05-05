import QtQuick 2.5
import QtQuick.Controls 1.4

Menu {
    property variant type
    signal itemClicked(string item)

    function update() {
        clear()
        addItem(qsTr("Info")).triggered.connect(function(){itemClicked("show" + type + "Info")})
        addItem(qsTr("Delete")).triggered.connect(function(){itemClicked("delete" + type )})
    }
}
