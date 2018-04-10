# $FreeBSD$

PORTNAME=	konsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde kde-applications # kde kde-applications-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	keditbookmarks:deskutils/keditbookmarks

USES=		cmake:outsource gettext pkgconfig kde:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm emoticons guiaddons i18n \
		iconthemes init itemmodels jobwidgets kdelibs4support kio \
		notifications notifyconfig parts pty service sonnet \
		textwidgets widgetsaddons windowsystem xmlgui
USE_QT5=	core dbus gui network printsupport script scripttools sql \
		widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
