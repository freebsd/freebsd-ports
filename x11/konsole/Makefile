PORTNAME=	konsole
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-applications # kde kde-applications-applications

PATCH_SITES=	https://invent.kde.org/utilities/konsole/-/commit/
PATCHFILES=	fb7f838fd3138a39aea3bcb2e91f923741587137.diff:-p1 \
		c78edfbac49852cec40efd5cbe73c341bc06c5ab.diff:-p1 \
		f24dd6acc28393ba6f731be1360731c01a9a1ef0.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	keditbookmarks:deskutils/keditbookmarks

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext pkgconfig kde:5 \
		qt:5 tar:xz
USE_KDE=	auth attica bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel guiaddons i18n \
		iconthemes init itemmodels jobwidgets kio \
		newstuff notifications notifyconfig parts pty service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network printsupport script scripttools sql \
		widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
