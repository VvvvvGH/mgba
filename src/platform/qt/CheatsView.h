/* Copyright (c) 2013-2015 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef QGBA_CHEATS_VIEW
#define QGBA_CHEATS_VIEW

#include <QWidget>

#include <functional>

#include "CheatsModel.h"

#include "ui_CheatsView.h"

struct GBACheatDevice;

namespace QGBA {

class CheatsView : public QWidget {
Q_OBJECT

public:
	CheatsView(GBACheatDevice* device, QWidget* parent = nullptr);

private slots:
	void load();
	void addSet();

private:
	void enterCheat(std::function<bool(GBACheatSet*, const char*)> callback);

	Ui::CheatsView m_ui;
	CheatsModel m_model;
};

}

#endif