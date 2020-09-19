#include "Port.h"
#include "PortPlugin.h"

#include <QtPlugin>

PortPlugin::PortPlugin(QObject *parent)
	: QObject(parent)
{
	m_initialized = false;
}

void PortPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
	if (m_initialized)
		return;

	// Add extension registrations, etc. here

	m_initialized = true;
}

bool PortPlugin::isInitialized() const
{
	return m_initialized;
}

QWidget *PortPlugin::createWidget(QWidget *parent)
{
	return new Port(parent);
}

QString PortPlugin::name() const
{
	return QLatin1String("Port");
}

QString PortPlugin::group() const
{
	return QLatin1String("GraphicsShow");
}

QIcon PortPlugin::icon() const
{
	return QIcon();
}

QString PortPlugin::toolTip() const
{
	return QLatin1String("");
}

QString PortPlugin::whatsThis() const
{
	return QLatin1String("Input and Output Port");
}

bool PortPlugin::isContainer() const
{
	return false;
}

QString PortPlugin::domXml() const
{
	return QLatin1String(R"(<?xml version="1.0" encoding="UTF-8"?>
						 <ui version="4.0">
						  <class>Port</class>
						  <widget class="QWidget" name="Port">
						   <property name="geometry">
							<rect>
							 <x>0</x>
							 <y>0</y>
							 <width>20</width>
							 <height>20</height>
							</rect>
						   </property>
						   <property name="windowTitle">
							<string>Form</string>
						   </property>
						   <widget class="QPushButton" name="outputPort">
							<property name="geometry">
							 <rect>
							  <x>0</x>
							  <y>0</y>
							  <width>20</width>
							  <height>20</height>
							 </rect>
							</property>
							<property name="minimumSize">
							 <size>
							  <width>0</width>
							  <height>0</height>
							 </size>
							</property>
							<property name="maximumSize">
							 <size>
							  <width>16777215</width>
							  <height>16777215</height>
							 </size>
							</property>
							<property name="styleSheet">
							 <string notr="true">QPushButton {
							 border: 1px solid #333333;
							 padding: 4px;
							 border-radius:10px;

							 background-color: rgb(255, 255, 255);
						 }

						 QPushButton:hover {
							 background-color: rgb(52, 167, 255);
							 border-color: #444444;
						 }

						 QPushButton:pressed {
							 background-color: rgb(46, 39, 239);
							 border-color: #333333;
							 color: yellow;
						 }

						 QPushButton:disabled {
							 color: #333333;
						 }</string>
							</property>
							<property name="text">
							 <string/>
							</property>
						   </widget>
						  </widget>
						  <resources/>
						  <connections/>
						 </ui>)");
}

QString PortPlugin::includeFile() const
{
	return QLatin1String("Port.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(portplugin, PortPlugin)
#endif // QT_VERSION < 0x050000
