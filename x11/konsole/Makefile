PORTNAME=	konsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator
WWW=		https://konsole.kde.org/

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext pkgconfig kde:5 \
		qt:5 tar:xz xorg
USE_KDE=	auth attica bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel guiaddons i18n \
		iconthemes init itemmodels jobwidgets kio \
		newstuff notifications notifyconfig parts pty service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui multimedia network printsupport sql \
		widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS
OPTIONS_EXCLUDE_purecap=	DOCS

.include <bsd.port.options.mk>

.if !${ABI:Mpurecap}
RUN_DEPENDS=	keditbookmarks:deskutils/keditbookmarks
USE_QT+=	script scripttools
.endif

.include <bsd.port.mk>
