# Created by: jhb
# $FreeBSD$

PORTNAME=	imwheel
PORTVERSION=	1.0.0.p12
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://jcatki.no-ip.org/pub/imwheel/ \
		SF/${PORTNAME}/${PORTNAME}-source/1.0.0pre12

DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p12/pre12/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to translate mouse wheel actions into X keyboard events

USE_XORG=	x11 xpm xtst xext xmu
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gpm

.include <bsd.port.options.mk>

post-patch:
.for i in imwheel.1 util.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/EMACS ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
