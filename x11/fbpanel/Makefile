# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	fbpanel
PORTVERSION=	6.1
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Lightweight, NETWM compliant X11 desktop panel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias gmake pkgconfig tar:tbz2
USE_GNOME=	gtk20
USE_XORG=	x11
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PORTDOCS=	CHANGELOG CREDITS NOTES README

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="${PORTNAME}" "${PORTNAME} NETWM compliant X11 desktop panel" \
		"${PORTNAME}" "${PORTNAME}" "System;" false

post-patch:
	@${REINPLACE_CMD} -e '/LDFLAGS/s/$$/ -lX11 -lm/' \
		${WRKSRC}/panel/Makefile.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/scripts/install.sh
	@${REINPLACE_CMD} -e 's|@DATADIR@|${DATADIR}|' \
		${WRKSRC}/data/man/${PORTNAME}.1.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/data/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${LN} -sf ${DATADIR}/images/logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
