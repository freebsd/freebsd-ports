# $FreeBSD$

PORTNAME=	konsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-applications # kde kde-applications-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	keditbookmarks:deskutils/keditbookmarks

USES=		cmake compiler:c++11-lang gettext pkgconfig kde:5 \
		qt:5 tar:xz
USE_KDE=	auth attica bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm emoticons globalaccel guiaddons i18n \
		iconthemes init itemmodels jobwidgets kdelibs4support kio \
		newstuff notifications notifyconfig parts pty service sonnet \
		textwidgets widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network printsupport script scripttools sql \
		widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
