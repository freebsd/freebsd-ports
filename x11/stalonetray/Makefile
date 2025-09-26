PORTNAME=	stalonetray
DISTVERSION=	0.9.0
CATEGORIES=	x11

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	STAnd-aLONE system tray
WWW=		https://d3adb5.github.io/stalonetray/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		libxslt>0:textproc/libxslt

USES=		autoreconf gmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	d3adb5
USE_XORG=	ice sm x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug \
		--disable-native-kde

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/stalonetrayrc.sample ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
