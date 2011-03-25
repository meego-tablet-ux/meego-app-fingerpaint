/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

import Qt 4.7
import MeeGo.Labs.Components 0.1
import MeeGo.App.Fingerpaint 0.1

Window {
    id: scene
    showsearch: false
    backgroundColor: "black"

    applicationPage: ApplicationPage {
        id: appPage
        title: qsTr("Fingerpaint!")
        menuWidth: 300
        menuHeight: 100
        menuContent: Item {
            Button {
                title: qsTr("Clear")
                color: "white"
                font.pixelSize: 26
                width: 210
                height: 71
                onClicked: {
                    fingerpaint.clear();
                    appPage.closeMenu();
                }
            }
        }
        Fingerpaint {
            id: fingerpaint
            parent: appPage.content
            anchors.fill: parent
        }
    }
}
