/*
 * Clippr - a magic clipboard assistant
 * Copyright (C) 2019 Johan Thelin
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QApplication>
#include <QMessageBox>
#include <QSystemTrayIcon>

#include "clipprwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable())
    {
        QMessageBox::critical(nullptr, QCoreApplication::translate("clippr_main", "Clippr"), QCoreApplication::translate("clipper_main", "Cannot start clipper as system tray is not available on this system."));
        return -1;
    }

    ClipprWindow w;

    a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
