# Created by: jhb
# $FreeBSD$

PORTNAME=	imwheel
DISTVERSION=	1.0.0pre12
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://jcatki.no-ip.org/pub/imwheel/ \
		SF/${PORTNAME}/${PORTNAME}-source/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to translate mouse wheel actions into X keyboard events

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	x11 xpm xtst xext xmu
USES=		dos2unix gmake
DOS2UNIX_FILES=	getopt/getopt.c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gpm

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in imwheel.1 util.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/EMACS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
