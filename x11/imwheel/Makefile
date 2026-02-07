PORTNAME=	imwheel
DISTVERSION=	1.0.0pre12
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${DISTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Utility to translate mouse wheel actions into X keyboard events
WWW=		https://imwheel.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix gmake xorg
USE_XORG=	x11 xpm xtst xext xmu
DOS2UNIX_FILES=	getopt/getopt.c
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-gpm

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in imwheel.1 util.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/imwheelrc ${STAGEDIR}${PREFIX}/etc/imwheelrc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/EMACS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
