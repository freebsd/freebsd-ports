# New ports collection makefile for:	p5-Tk400
# Version required:			2.00
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1996/11/18 08:47:32 asami Exp $
#

DISTNAME=	Tk400.200
PKGNAME=	p5-Tk400-2.00
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/HTML/Parse.pm:${PORTSDIR}/www/p5-libwww \
		${PREFIX}/lib/perl5/site_perl/IO.pm:${PORTSDIR}/net/p5-IO
LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN1=		tkweb.1
MAN3=		Tk::After.3 Tk::Axis.3 Tk::ColorEditor.3 Tk::Dial.3 \
		Tk::DragDrop::Common.3 Tk::DragDrop::SunConst.3 \
		Tk::FileDialog.3 Tk::FileSelect.3 Tk::Font.3 \
		Tk::Ghostscript.3 Tk::HTML::IO.3 Tk::IO.3 \
		Tk::Internals.3 Tk::Parse.3 Tk::ROText.3 \
		Tk::Table.3 Tk::Tcl-perl.3 Tk::TextUndo.3 \
		Tk::UserGuide.3 Tk::WaitBox.3 Tk::pTk.3 blib.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
