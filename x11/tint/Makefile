# New ports collection makefile for:	tint
# Date created:				21 July 2008
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tint
PORTVERSION=	0.6.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/clock

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

PROJECTHOST=	tint2
USE_GNOME=	pango
USE_XORG=	xinerama xrandr
USE_EFL=	imlib2
USE_GMAKE=	yes

MAKE_ENV+=	DESTDIR=${PREFIX}

PLIST_FILES=	bin/tint \
		etc/xdg/tint/tintrc
PLIST_DIRS=	etc/xdg/tint

PORTDOCS=	ChangeLog README tint-0.6.pdf

WRKSRC=		${WRKDIR}/${PORTNAME}/src
ALL_TARGET=	${PORTNAME}

post-patch:
	@${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${SED} -e 's#/usr/bin#/bin#g' \
		${WRKSRC}/Makefile.dist > ${WRKSRC}/Makefile

pre-install:
	${ECHO} "rmdir ${X11BASE}/etc/xdg 2>/dev/null || true" > \
		${WRKDIR}/pkg-deinstall
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/tint-0.6.pdf ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../tintrc* ${EXAMPLESDIR}
.for N in 1 2 3 4
PLIST_FILES+=	${EXAMPLESDIR_REL}/tintrc${N}
.endfor
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.mk>
