# New ports collection makefile for:   sawmill
# Version required:    0.20.1
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	sawmill-0.20.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://sawmill.sourceforge.net/pub/sawmill/ \
		http://www.gnome.gr.jp/~yatt/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} sawmill-0.20.1-ja.po

.if defined(USE_I18N)
PATCH_SITES=	http://www.gnome.gr.jp/~yatt/
PATCHFILES=	sawmill-0.20.1-kondara.patch
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		rep.6:${PORTSDIR}/lang/librep
.if !defined(NOGNOME)
LIB_DEPENDS+=	capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif
BUILD_DEPENDS=	${LOCALBASE}/libexec/rep/${ARCH}--freebsd${OSREL}/libgtk.so:${PORTSDIR}/x11-toolkits/rep-gtk
RUN_DEPENDS=	${LOCALBASE}/libexec/rep/${ARCH}--freebsd${OSREL}/libgtk.so:${PORTSDIR}/x11-toolkits/rep-gtk

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
#GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share --with-readline
.if !defined(NOGNOME)
CONFIGURE_ARGS+=	--enable-capplet
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include\
			-I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

.if defined(NOGNOME)
PLIST=		${PKGDIR}/PLIST.nognome
.endif

post-extract:
	@${CP} ${DISTDIR}/sawmill-0.20.1-ja.po ${WRKSRC}/po/ja.po

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info --section="X11 window manager" \
	--entry="* sawmill: (sawmill).           sawmill programming manual" \
	${PREFIX}/info/sawmill.info ${PREFIX}/info/dir

.include <bsd.port.mk>
