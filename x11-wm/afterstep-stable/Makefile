# New ports collection makefile for:	afterstep-stable
# Date created:		1 May 1998
# Whom:			Brett Taylor
#
# $FreeBSD$
#

PORTNAME=	afterstep
PORTVERSION=	1.8.11
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	stable
DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		rplay.1:${PORTSDIR}/audio/rplay

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--enable-i18n \
		--with-png-includes="${LOCALBASE}/include" \
		--with-png-libs="${LOCALBASE}/lib" \
		--with-jpeg-includes="${LOCALBASE}/include" \
		--with-jpeg-libs="${LOCALBASE}/lib" \
		--with-helpcommand="xterm -e man"

.if defined(WITH_DIFFERENT_LOOKNFEELS)
CONFIGURE_ARGS+=	--enable-different-looknfeels
.endif

.if !defined(WITH_SAVEWINDOWS)
CONFIGURE_ARGS+=	--disable-savewindows
.endif

MAN1=	Animate.1x Audio.1x Banner.1x Cascade.1x Clean.1x Form.1x Gnome.1x \
	Ident.1x Pager.1x Save.1x Script.1x Scroll.1x Tile.1x Wharf.1x \
	WinList.1x Zharf.1x afterstep.1x asetroot.1x

post-patch:
.for file in wharf.in zharf.in
	${PERL} -pi -e 's,linux_penguin,monitor_bsd,' \
		${WRKSRC}/afterstep/${file}
.endfor
	${PERL} -pi.orig -e 's,/usr/X11/,${X11BASE}/,' \
		${WRKSRC}/src/afterstep/afterstep.man

post-install:
	@${INSTALL_DATA} ${FILESDIR}/monitor_bsd.xpm ${PREFIX}/share/afterstep/desktop/icons/common/
.if defined(WITH_DIFFERENT_LOOKNFEELS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===>  The WinList module is broken with different-looknfeels.  Don't use it."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
