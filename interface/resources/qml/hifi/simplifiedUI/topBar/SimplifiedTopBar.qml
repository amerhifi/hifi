//
//  SimplifiedTopBar.qml
//
//  Created by Zach Fox on 2019-05-02
//  Copyright 2019 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

import QtQuick 2.10
import hifi.simplifiedUI.simplifiedControls 1.0 as SimplifiedControls

Rectangle {
    id: root
    focus: true
    anchors.fill: parent
    
   Item {
    id: test
    anchors.fill: parent
    Rectangle {
        anchors.fill:parent 
          Image {
             id: avatarButtonImage
             source: "../images/Island-map-v1.png"
             width: parent.width
             height: parent.height
          }

          Row{
          padding: 10
          spacing: 10
             Text{
                id : xx
                text: 'xx'
                 font.pointSize: 24
             }

            Text{
                id :yy
                text: 'yy'
                  font.pointSize: 24
            }
          }
            MouseArea{
              anchors.fill: parent
               onClicked: {
                yy.text= mouseX
                xx.text=mouseY
                MyAvatar.goToLocation(mouseX,-95,-mouseY)
              }
           }  
        }
      }
}