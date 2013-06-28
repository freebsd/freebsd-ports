# Created by: lab@fnurt.net
# $FreeBSD$

PORTNAME=	larswm
PORTVERSION=	7.5.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiling Window Manager for X

USES=		imake
USE_XORG=	ice sm x11 xext xmu xt

MAN1=		larsclock.1 larsmenu.1 larsremote.1 larswm.1
PORTDOCS=	ChangeLog README README.9menu README.9wm \
		sample.larswmrc sample.xsession
PLIST_FILES=	bin/larsclock bin/larsmenu bin/larsremote bin/larswm

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} $(WRKSRC)/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
