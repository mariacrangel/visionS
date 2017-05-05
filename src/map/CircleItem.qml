
import QtQuick 2.5
import QtLocation 5.6

//TODO: remove/refactor me when items are integrated

MapCircle {

    color: "#46a2da"
    border.color: "#190a33"
    border.width: 2
    smooth: true
    opacity: 0.25

    function setGeometry(markers, index){
        center.latitude = markers[index].coordinate.latitude
        center.longitude = markers[index].coordinate.longitude
        radius= center.distanceTo(markers[index + 1].coordinate)
    }
}
