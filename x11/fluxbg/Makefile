# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fluxbg
PORTVERSION=	0.7
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background changer for fluxbox/blackbox

LIB_DEPENDS=	libgtkmm-2.0.so:${PORTSDIR}/x11-toolkits/gtkmm20
RUN_DEPENDS=	fbsetbg:${PORTSDIR}/x11-wm/fluxbox

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/src/fluxbg_conf.cc

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
