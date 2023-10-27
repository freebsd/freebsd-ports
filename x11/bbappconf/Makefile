PORTNAME=	bbappconf
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application configuring tool for the blackbox window manager
WWW=		https://bbtools.sourceforge.net/

USES=		xorg
USE_CXXSTD=	c++14
USE_XORG=	x11

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbappconf ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bbtools
.for a in README.bbappconf bbappconf.bb bbappconf.nobb
	${INSTALL_DATA} ${WRKSRC}/data/${a} ${STAGEDIR}${PREFIX}/share/bbtools
.endfor

.include <bsd.port.mk>
