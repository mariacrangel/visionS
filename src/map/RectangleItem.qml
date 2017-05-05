import QtQuick 2.5
import QtLocation 5.6

MapRectangle {
    id: mapRectangle

    color: "#46a2da"
    border.color: "#190a33"
    border.width: 2
    smooth: true
    opacity: 0.25

    function setGeometry(markers, index){
        topLeft.latitude = Math.max(markers[index].coordinate.latitude, markers[index + 1].coordinate.latitude)
        topLeft.longitude = Math.min(markers[index].coordinate.longitude, markers[index + 1].coordinate.longitude)
        bottomRight.latitude = Math.min(markers[index].coordinate.latitude, markers[index + 1].coordinate.latitude)
        bottomRight.longitude = Math.max(markers[index].coordinate.longitude, markers[index + 1].coordinate.longitude)
    }

}
