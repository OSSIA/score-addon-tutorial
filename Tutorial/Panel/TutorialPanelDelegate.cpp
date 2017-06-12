#include "TutorialPanelDelegate.hpp"
#include <QFormLayout>
#include <QQuickWidget>
#include <QLabel>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickWindow>
#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QQuickView>
namespace Tutorial
{

PanelDelegate::PanelDelegate(
        const iscore::GUIApplicationContext& ctx):
    iscore::PanelDelegate{ctx}
{
    m_widget = new QWidget;
    auto lay = new QFormLayout{m_widget};

    lay->addWidget(new QLabel{tr("This is a panel.")});
}

QWidget* PanelDelegate::widget()
{
    return m_widget;
}

const iscore::PanelStatus& PanelDelegate::defaultPanelStatus() const
{
    static const iscore::PanelStatus status{
        true,
        Qt::RightDockWidgetArea,
        10,
        QObject::tr("Tutorial"),
        QObject::tr("Ctrl+T")};

    return status;
}

void PanelDelegate::on_modelChanged(
        iscore::MaybeDocument oldm,
        iscore::MaybeDocument newm)
{

}

void PanelDelegate::setNewSelection(
        const Selection& s)
{
}


std::unique_ptr<iscore::PanelDelegate> PanelDelegateFactory::make(
        const iscore::GUIApplicationContext& ctx)
{
    return std::make_unique<PanelDelegate>(ctx);
}




QMLPanelDelegate::QMLPanelDelegate(
        const iscore::GUIApplicationContext& ctx):
    iscore::PanelDelegate{ctx}
{
  QQuickView *view = new QQuickView(QUrl("qrc:///TutorialPanel.qml"));
  auto w = QWidget::createWindowContainer(view);
  view->setClearBeforeRendering(true);
  view->setColor(qApp->palette().background().color());
  view->setResizeMode(QQuickView::ResizeMode::SizeRootObjectToView);
  m_widget = w;
}


QWidget* QMLPanelDelegate::widget()
{
    return m_widget;
}

const iscore::PanelStatus& QMLPanelDelegate::defaultPanelStatus() const
{
    static const iscore::PanelStatus status{
        true,
        Qt::RightDockWidgetArea,
        100,
        QObject::tr("Tutorial QML"),
        QObject::tr("Ctrl+U")};

    return status;
}

void QMLPanelDelegate::on_modelChanged(
        iscore::MaybeDocument oldm,
        iscore::MaybeDocument newm)
{

}

void QMLPanelDelegate::setNewSelection(
        const Selection& s)
{
}


std::unique_ptr<iscore::PanelDelegate> QMLPanelDelegateFactory::make(
        const iscore::GUIApplicationContext& ctx)
{
    return std::make_unique<QMLPanelDelegate>(ctx);
}

}
