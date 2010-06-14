# New ports collection makefile for:	tint
# Date created:				21 July 2008
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tint2
PORTVERSION=	0.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LICENSE=	GPLv2

MAKE_JOBS_SAFE=	yes

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

PROJECTHOST=	tint2
USE_GNOME=	pango glib20
USE_XORG=	xinerama xrandr xdamage xcomposite
USE_EFL=	imlib2
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-battery --disable-tint2conf

PLIST_FILES=	bin/tint2 \
		etc/xdg/tint2/tint2rc \
		share/tint2/default_icon.png
PLIST_DIRS=	etc/xdg/tint2 \
		share/tint2

MAN1=		tint2.1

PORTDOCS=	AUTHORS ChangeLog README NEWS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not link
.endif

post-patch:
	@${CP} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.presed
	@${SED} -e "s# install-dist_docDATA##" \
	    ${WRKSRC}/Makefile.in.presed > ${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/src/tint.c ${WRKSRC}/src/tint.c.presed
	@${SED} -e "s#SIGCLD#SIGCHLD#g" ${WRKSRC}/src/tint.c.presed > \
	    ${WRKSRC}/src/tint.c

pre-install:
	@${ECHO} "rmdir ${X11BASE}/etc/xdg 2>/dev/null || true" > \
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
	@for file in ${RCS}; do \
	${INSTALL_DATA} ${WRKSRC}/sample/$${file} ${EXAMPLESDIR}; \
	done
RCS=	black_single_desktop.tint2rc default.tint2rc horizontal_icon_only.tint2rc rounded_multi_desktop.tint2rc tint2rc vertical_icon_only.tint2rc white_single_desktop.tint2rc
.for file in ${RCS}
PLIST_FILES+=	${EXAMPLESDIR_REL}/${file}
.endfor
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.post.mk>
