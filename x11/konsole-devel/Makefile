PORTNAME=	konsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator
WWW=		https://konsole.kde.org/

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
LIB_DEPENDS=	libicui18n.so:devel/icu

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext gl kde:6 pkgconfig qt:6 \
		tar:xz xorg
USE_KDE=	attica5 bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons globalaccel guiaddons i18n \
		iconthemes jobwidgets kio newstuff notifications notifyconfig \
		parts pty service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		5compat base multimedia
USE_GL=		gl opengl
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
