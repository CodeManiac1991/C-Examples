#include <QGuiApplication>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DCore/QTransform>

using namespace Qt3DExtras;
using namespace Qt3DCore;
using namespace Qt3DRender;

Qt3DCore::QEntity *createScene();

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Все классы QT3D обернуты в namespaces, поэтому 3dwindow создаем через него
    Qt3DWindow      view; // основное окно

    // Entity - это сущность. В данном случае мы делаем сущность сцены
    QEntity         *rootEntity = createScene();

    // обратимся к камере в qt3dwindow
    QCamera         *camera     = view.camera();
    camera->lens()->setPerspectiveProjection(60.0f, (float) view.width() / view.height(), 0.1f, 1000.0f);
    // отдаление от центра камеры, по z от 0 дна 40 юнитов
    camera->setPosition( QVector3D(0.0f, 0.0f, 80.0f) );
    // привязать камеру к какой то точке чтобы можно было вокруг нее крутить
    camera->setViewCenter( QVector3D(0.0f, 0.0f, 0.0f) );

    //создаем контроллер камеры для передвижения по вьюхе (орбит позволяет крутить вокруг объекта)
    QOrbitCameraController *cameraController = new QOrbitCameraController(rootEntity);
    cameraController->setCamera(camera);
    cameraController->setLookSpeed(100.0f);
    cameraController->setLinearSpeed(50.0f);

    view.setRootEntity(rootEntity);
    view.show();

    return app.exec();
} // main

Qt3DCore::QEntity *createScene()
{
    QEntity    *resultEntity = new QEntity;

    // создаем торус и указываем ему родителя чтобы сначала разрушились дети а потом родители
    QTorusMesh *torusMesh    = new QTorusMesh(resultEntity);
    torusMesh->setRadius(15.0f);
    torusMesh->setMinorRadius(6.0f);
    torusMesh->setSlices(16);
    torusMesh->setRings(32);

    // создаем материал для торуса
    QPhongMaterial       *torusMaterial  = new QPhongMaterial(resultEntity);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform(resultEntity);

    resultEntity->addComponent(torusMesh);
    resultEntity->addComponent(torusMaterial);
    resultEntity->addComponent(torusTransform);

    // Добавим источник света
    QEntity              *lightEntity    = new QEntity(resultEntity);
    QPointLight          *pointLight     = new QPointLight(lightEntity);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(resultEntity);
    lightTransform->setTranslation( QVector3D(0.0f, 0.0f, 0.0f) );

    resultEntity->addComponent(pointLight);
    resultEntity->addComponent(lightTransform);

    return resultEntity;
} // createScene
