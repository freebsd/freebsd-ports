# New ports collection makefile for:	tint
# Date created:				21 July 2008
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tint2
PORTVERSION=	0.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

PROJECTHOST=	tint2
USE_GNOME=	pango glib20
USE_XORG=	xinerama xrandr
USE_EFL=	imlib2
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-battery

PLIST_FILES=	bin/tint2 \
		etc/xdg/tint2/tint2rc
PLIST_DIRS=	etc/xdg/tint2

MAN1=		tint2.1

PORTDOCS=	AUTHORS ChangeLog README NEWS

post-patch:
	@${CP} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.presed
	@${SED} -e "s# install-dist_docDATA##" \
	    ${WRKSRC}/Makefile.in.presed > ${WRKSRC}/Makefile.in

pre-install:
	${ECHO} "rmdir ${X11BASE}/etc/xdg 2>/dev/null || true" > \
		${WRKDIR}/pkg-deinstall
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tintrc* ${EXAMPLESDIR}
.for N in 1 2 3 4 5 6
PLIST_FILES+=	${EXAMPLESDIR_REL}/tintrc0${N}
.endfor
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.mk>
