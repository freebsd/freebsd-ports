# New ports collection makefile for:	kwix
# Date created:				30 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kwix
PORTVERSION=	1.0.9
CATEGORIES=	x11-wm kde
MASTER_SITES=	ftp://ftp.kde.com/pub/Art_Music/Themes/KwiX/ \
		ftp://ftp.thekompany.com/pub/kwix/
DISTNAME=	${PORTNAME}-${PORTVERSION}kb

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	kwin:${PORTSDIR}/x11/kdebase2
LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2 \
		intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	kwin:${PORTSDIR}/x11/kdebase2

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++"

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure

.include <bsd.port.mk>
