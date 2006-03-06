# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.8
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	e16-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A very artistic X window manager

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

BROKEN=		Incomplete pkg-plist

DATADIR=	${PREFIX}/share/e16

CONFLICTS=	x11-wm/enlightenment-devel-[0-9]*
USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd --disable-esdtest --disable-dependency-tracking \
		--disable-rpath
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.if !defined(WITHOUT_ESOUND)
USE_GNOME=	esound
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_FILES=	share/locale/bg/LC_MESSAGES/e16.mo \
		share/locale/bs/LC_MESSAGES/e16.mo \
		share/locale/da/LC_MESSAGES/e16.mo \
		share/locale/de/LC_MESSAGES/e16.mo \
		share/locale/en_US/LC_MESSAGES/e16.mo \
		share/locale/es/LC_MESSAGES/e16.mo \
		share/locale/fr/LC_MESSAGES/e16.mo \
		share/locale/hu/LC_MESSAGES/e16.mo \
		share/locale/ja/LC_MESSAGES/e16.mo \
		share/locale/ko/LC_MESSAGES/e16.mo \
		share/locale/nl/LC_MESSAGES/e16.mo \
		share/locale/no/LC_MESSAGES/e16.mo \
		share/locale/pl/LC_MESSAGES/e16.mo \
		share/locale/pt/LC_MESSAGES/e16.mo \
		share/locale/pt_BR/LC_MESSAGES/e16.mo \
		share/locale/ru/LC_MESSAGES/e16.mo \
		share/locale/sv/LC_MESSAGES/e16.mo \
		share/locale/tr/LC_MESSAGES/e16.mo
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.pre.mk>

.if (${MACHINE} == "alpha") && (${X_WINDOW_SYSTEM:L} == xfree86-3)
CONFIGURE_ARGS+=	--disable-zoom
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/scripts/e_gen_menu

.include <bsd.port.post.mk>
