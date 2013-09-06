# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	bbkeys
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Keygrabber for the Blackbox window manager

LICENSE=	MIT

BUILD_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USES=		perl5 pkgconfig
USE_PERL5=	build
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CPPFLAGS+=	`pkg-config --cflags xft`
LDFLAGS+=	`pkg-config --libs xft`

MAN1=		bbkeys.1
MAN5=		bbkeysrc.5
PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TODO

PLIST_FILES=	bin/bbkeys %%DATADIR%%/bbkeysrc %%DATADIR%%/defaultStyle
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#: install-docDATA#:#' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S#^#${WRKSRC}/#} ${DOCSDIR}
.endif

.include <bsd.port.mk>
