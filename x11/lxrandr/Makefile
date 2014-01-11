# Created by: Eric Turgeon <ericturgeon.bsd@gmail.com>
# $FreeBSD$

PORTNAME=	lxrandr
PORTVERSION=	0.1.2
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXRandR%20%28monitor%20config%20tool%29/LXRandR%20${PORTVERSION}

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	LXDE screen manager

LICENSE=	GPLv2

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	gtk20
USE_XORG=	xrandr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
