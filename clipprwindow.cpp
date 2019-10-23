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

#include "clipprwindow.h"

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QMimeData>
#include <QSystemTrayIcon>

ClipprWindow::ClipprWindow(QWidget *parent) : QMainWindow(parent)
{
    m_trayMenu = new QMenu(this);
    QAction *action = m_trayMenu->addAction(tr("Exit"));

    connect(action, &QAction::triggered, this, &ClipprWindow::onExit);

    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setIcon(QIcon(":/images/logo.png"));
    m_trayIcon->setContextMenu(m_trayMenu);
    m_trayIcon->show();

    connect(QGuiApplication::clipboard(), &QClipboard::changed, this, &ClipprWindow::onClipboardChanged);
}

void ClipprWindow::onExit()
{
    qApp->quit();
}

// TODO temporary include
#include <QMessageBox>

void ClipprWindow::onClipboardChanged(QClipboard::Mode /* mode */)
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString text = "";
    if (clipboard->mimeData()->hasText())
    {
        text = clipboard->mimeData()->text();
    }
    QMessageBox::information(nullptr, tr("Clippr"), tr("Formats: \n- %1\n\n%2").arg(clipboard->mimeData()->formats().join("\n- ")).arg(text));
}
