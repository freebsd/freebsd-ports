# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.5
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://freebsd.sinica.edu.tw/pub/clive/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		Marble.etheme \
		BlueSteel.etheme.zh_TW.Big5 \
		BrushedMetal-Tigert.etheme.zh_TW.Big5 \
		ShinyMetal.etheme.zh_TW.Big5
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	Fnlib.0:${PORTSDIR}/graphics/fnlib \
		ghttp.1:${PORTSDIR}/www/libghttp \
		intl.4:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	esound imlib
USE_REINPLACE=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1 \
			  -I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

.include <bsd.port.pre.mk>

.if (${MACHINE} == "alpha") && (${XFREE86_VERSION} == 3)
CONFIGURE_ARGS+=--disable-zoom
.endif

MAN1=		enlightenment.1

pre-patch:
	@${REINPLACE_CMD} -e 's| wctype.h||' ${WRKSRC}/configure

pre-build:
.for i in Marble.etheme BlueSteel.etheme.zh_TW.Big5 BrushedMetal-Tigert.etheme.zh_TW.Big5 ShinyMetal.etheme.zh_TW.Big5
	${CP} ${DISTDIR}/$i ${WRKSRC}/src/themes
.endfor

post-install:
	${RM} ${PREFIX}/share/enlightenment/themes/Ganymede/dialogs/#dialogs.cfg#
	${CHOWN} -R root:wheel ${PREFIX}/share/enlightenment/themes
	${CHMOD} -R a+rX ${PREFIX}/share/enlightenment/themes

.include <bsd.port.post.mk>
