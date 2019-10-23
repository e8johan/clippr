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

#ifndef CLIPPRWINDOW_H
#define CLIPPRWINDOW_H

#include <QMainWindow>

#include <QClipboard>

class QMenu;
class QSystemTrayIcon;

class ClipprWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ClipprWindow(QWidget *parent = nullptr);

signals:

private slots:
    void onClipboardChanged(QClipboard::Mode);

    void onExit();

private:
    QMenu *m_trayMenu;
    QSystemTrayIcon *m_trayIcon;
};

#endif // CLIPPRWINDOW_H
