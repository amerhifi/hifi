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
   // property variant maps [{name:'birds', coord:{.67, .80}},{name:'cacti', coord:{.51,.79 },{name:'', coord:{ }]
    
    id: test
    anchors.fill: parent
   
    Rectangle {
        anchors.fill: parent 
         color: '#000000'
          Image {
             id: avatarButtonImage
             source: "../images/Island-map-v1.png"
             width: parent.width /1.25
             height:parent.height /1.25
             x: parent.width *.1
             y: parent.height *.1
             }

          Row{
          padding: 10
          spacing: 10
             Text{
                id : xx
                text: 'xx'
                font.pointSize: 24
                color: '#FFFFFF'
             }

            Text{
                id :yy
                text: 'yy'
                font.pointSize: 24
                color: '#FFFFFF'

            }
          }
            MouseArea{
              anchors.fill: parent
               onClicked: {
                var x = parseFloat(mouseX / (parent.width / 1.25 + parent.height *.1)).toFixed(2)
                var y = parseFloat(mouseY / (parent.height /1.25 + parent.height *.1)).toFixed(2)
                
               // yy.text= maps[0].name
                xx.text=y
                

                MyAvatar.goToLocation(mouseX,-95,-mouseY)
              }
           }  
        }
      }
}