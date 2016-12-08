# Created by: Eric Turgeon <ericturgeon.bsd@gmail.com>
# $FreeBSD$

PORTNAME=	lxrandr
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXRandR%20%28monitor%20config%20tool%29/LXRandR%20${PORTVERSION}

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	LXDE screen manager

LICENSE=	GPLv2

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	gtk20 intltool
USE_XORG=	xrandr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
